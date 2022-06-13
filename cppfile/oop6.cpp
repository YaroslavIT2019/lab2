#include <iostream>

using namespace std;

class Figura
{
public:
    virtual void Show() = 0;
    virtual void Destroy() = 0;
    virtual void Rotate(int angle) = 0;
    virtual void Move(int length_x, int length_y) = 0;
};

class Circle : public Figura
{
public:
    int x_center = 0, y_center = 0, angle_of_rotation = 0, scale = 0;

    Circle(int x_center, int y_center, int angle_of_rotation, int scale)
    {
        this->x_center = x_center;
        this->y_center = y_center;
        this->angle_of_rotation = angle_of_rotation;
        this->scale = scale;
    }

    void Show() override
    {
        cout << "Show circle" << endl;
        cout << "x: " << x_center << "\t";
        cout << "y: " << y_center << "\t";
        cout << "scale: " << scale << "\t";
        cout << endl;
    }
    void Destroy() override
    {
        cout << "Destroy the circle" << endl;
    }
    void Rotate(int angle) override
    {
        cout << "Without changes" << endl;
    }
    void Move(int length_x, int length_y) override
    {
        x_center += length_x;
        y_center += length_y;

        cout << "New x: " << x_center << "\t";
        cout << "New y: " << y_center << "\t";
        cout << endl;
    }
};

int main()
{
    int x, y, angle_of_rotation, scale;
    cout << "Enter x: " << "\t";
    cin >> x;
    cout << "Enter y: " << "\t";
    cin >> y;
    cout << "Enter angle of rotation: " << "\t";
    cin >> angle_of_rotation;
    cout << "Enter scale: " << "\t";
    cin >> scale;

    Circle c (x, y, angle_of_rotation, scale);
    Figura* f;

    f = &c;

    f->Show();
    f->Rotate(4);
    f->Move(5, 7);
    f->Destroy();
}