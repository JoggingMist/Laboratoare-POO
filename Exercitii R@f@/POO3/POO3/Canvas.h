class Canvas
{
    char **CANVAS;
    int Width, Height;
    const char EmptyPoint=32;
public:
    Canvas(int width, int height);
    void DrawCircle(int x, int y, int ray, char ch);
    void DrawElipse(int x, int y, int ray1, int ray2, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print();
    void Clear();
};
