#include <iostream>
#include "string.h"
#include "zip.h"
#include <dirent.h>

bool ZipFile(const char* inputFileName, const char* outZipFileName )
{
     // ZIP dosyasını oluşturun veya var olan bir ZIP dosyasını açın
    struct zip* archive = zip_open(outZipFileName, ZIP_CREATE | ZIP_TRUNCATE, NULL);

    if (!archive) {
        printf("ZIP dosyasini olusturma hatasi!\n");
        return false;
    }

    struct zip_source* source = zip_source_file(archive, inputFileName, 0, 0);
 

    // ZIP dosyasına dosyayı ekleyin
    int error1 = zip_file_add(archive, inputFileName, source, ZIP_FL_ENC_UTF_8);


    if (error1 < 0) {
        printf("Dosya ziplenirken hata olustu: %s\n", zip_strerror(archive));
        return false;
    }

    // ZIP dosyasını kapatın
    zip_close(archive);

    printf("Dosya basariyla ziplendi: %s\n", outZipFileName);
    return true;
}

bool ZipDirectory(const char* inputDirectory, const char* outZipFileName) {
    // ZIP dosyasını oluşturun veya var olan bir ZIP dosyasını açın
    struct zip* archive = zip_open(outZipFileName, ZIP_CREATE | ZIP_TRUNCATE, NULL);

    if (!archive) {
        printf("ZIP dosyasini olusturma hatasi!\n");
        return false;
    }

    // Klasörü aç
    DIR* dir = opendir(inputDirectory);
    if (!dir) {
        printf("Klasor acilamadi: %s\n", inputDirectory);
        return false;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // "." ve ".." girişlerini atlayın
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Dosyanın tam yolu
        char filePath[PATH_MAX];
        snprintf(filePath, sizeof(filePath), "%s/%s", inputDirectory, entry->d_name);

        struct zip_source* source = zip_source_file(archive, filePath, 0, 0);

        // ZIP dosyasına dosyayı ekleyin
        int error = zip_file_add(archive, entry->d_name, source, ZIP_FL_ENC_UTF_8);

        if (error < 0) {
            printf("Dosya ziplenirken hata olustu: %s\n", zip_strerror(archive));
            closedir(dir);
            zip_close(archive);
            return false;
        }
    }

    // Klasörü kapatın
    closedir(dir);

    // ZIP dosyasını kapatın
    zip_close(archive);

    printf("Klasor basariyla ziplendi: %s\n", outZipFileName);
    return true;
}