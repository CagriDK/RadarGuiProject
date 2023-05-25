class State {
public:
    virtual ~State() {}
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput() = 0;
};