#include <iostream>
#include <string>
#include <math.h>
#include <vector>


using namespace std;

//string repl(char charToDisplay, int dispQty)
//{
//    string returnedString = "";
//    for (int i = 0; i < dispQty; i++)
//    {
//        returnedString.push_back(charToDisplay);
//    }
//    return returnedString;
//}

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: char showMenu(vector<string> menu)
 * Purpose      : General purpose function to display a menu list based on the passed parameter
 * Parameters   : vector<string> menu --> an array of strings to display as a menu
 * Returns      : Returns the character pressed by the user
*/
//int showMenu(vector<string> menu)
//{
//    int ch = 0;
//
//    for (int i = 0; i < (int)menu.size(); i++)
//    {
//        cout << menu[i] << endl;
//    }
//
//    cout << "Choice: ";
//    cin >> ch;
//
//    return ch;
//}

// Class definitions

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles Assessment 1
 * Class Name   : Shapes
 * Purpose      : Base class for all shapes
 * Parameters   : N/A
 * Returns      : N/A
*/
class Shapes

{
private:
    float base = 0.0, height = 0.0, side = 0.0, radius = 0.0, result = 0.0;

public:
    /***********************************************************************************************************************************************
     * Title        : CS-105 Development Principles Assessment 1
     * Function Name: string repl(char charToDisplay, int dispQty)
     * Purpose      : General purpose function to display a series of characters - sort of replicating the display. This is useful for displaying lines.
     * Parameters   : char charToDisplay --> the character to display repeatedly, int dispQty --> number of times to display the character.
     * Returns      : Returns a 'string' which contains the replicated characters.
     * Author       : Gilberto Gabon
     *************************************************************************************************************************************************/
    string repl(char charToDisplay, int dispQty)
    {
        string returnedString = "";
        for (int i = 0; i < dispQty; i++)
        {
            returnedString.push_back(charToDisplay);
        }
        return returnedString;
    }

    // Define getters
    float getBase() {
        return base;
    }
    float getHeight() {
        return height;
    }
    float getSide() {
        return side;
    }

    float getRadius() {
        return radius;
    }
    float getResult() {
        return result;
    }

    // Define setters
    void setBase(float b)
    {
        base = b;
    }
    void setHeight(float h)
    {
        height = h;
    }
    void setSide(float s)
    {
        side = s;
    }
    void setRadius(float r)
    {
        radius = r;
    }

    void setResult(float res)
    {
        result = res;
    }

    // Default function - based on a rectangle

    void calculateArea()
    {

        result = base * height;
    }

    void calculatePerimeter()
    {
        result = 2 * (base + height);
    }

    void getData()
    {
        cout << "  \nEnter base (cm): ";
        cin >> base;
        cout << "Enter height (cm): ";
        cin >> height;
    }

    void giveResult() {
        cout << "The result is: " << result;
    }

    void drawShape() {
        // base shape is a rectangle
        cout << endl;
        for (int y = 1; y <= height / 2; y++) {
            cout << repl('.', base) << endl;
        }
        cout << endl;
    }
};

class Square : public Shapes {

public:
    void getData() {
        float side;
        cout << "  \nEnter side (cm): ";
        cin >> side;
        setBase(side);   // update the base
        setHeight(side); // update the height
    }

    void drawShape() {

        cout << endl;
        for (int y = 1; y <= getHeight(); y++) {

            cout << repl('.', getBase() * 2) << endl;
        }
        cout << endl;
    }
};

class Triangle : public Shapes {

public:
    void getData() { //user input base, height & side
        float base, height, side;
        cout << "  \nEnter base (cm): ";
        cin >> base;
        cout << "Enter height (cm): ";
        cin >> height;
        cout << "Enter side (cm): ";
        cin >> side;
        setBase(base);     
        setHeight(height); 
        setSide(side);     
    }

    void calculateArea() { // overloaded function
        float result;
        float b = getBase();
        float h = getHeight();
        result = 0.5 * b * h; 
        setResult(result);    
    }

    void calculatePerimeter() { // overloaded function
    
        float result;
        float b = getBase();
        float h = getHeight();
        float s = getSide();
        result = b + h + s; 
        setResult(result);  
    }

    void drawShape() {

        int draw = 0;
        draw = getBase() / getHeight();
        cout << "\n." << endl;
        for (int y = 1; y <= getHeight(); y++)
        {

            cout << repl('.', draw * y) << endl;
        }
        cout << endl;
    }
};

class Circle : public Shapes
{

public:
    void getData() {
        float radius;
        cout << "\nEnter radius (cm): ";
        cin >> radius;
        setRadius(radius);
    }

    void calculateArea() {// overloaded function
        float result;
        float radius = getRadius();
        result = 3.14159 * radius * radius;
        setResult(result);       
    }

    void calculatePerimeter() { // overloaded function
        float result;
        float radius = getRadius();
        result = 2 * 3.14159 * radius;
        setResult(result);
    }
    //    void drawShape()
    //    {
    //        float r = getRadius();
    //        const int SIZE = 2 * r; // diameter of the circle
    //
    //        char canvas[SIZE][SIZE]; // size of the drawing canvass = diameter of the circle
    //
    //        // Initialize contents of the array with blanks
    //        for (int i = 0; i < SIZE; i++)
    //        {
    //            for (int j = 0; j < SIZE; j++)
    //            {
    //                canvas[i][j] = ' '; // initialize with SPACE character (blank)
    //            }
    //        }
    //
    //        for (int row = 0; row < SIZE; row++)
    //        {
    //
    //            for (int col = 0; col < SIZE; col++)
    //            {
    //
    //                int x = col - SIZE / 2;
    //                int y = SIZE / 2 - row;
    //
    //                int r2 = x * x + y * y; // plotting equation of circle r^2 = x^2 + y^2
    //
    //                if (r2 < (r * r))
    //                {
    //                    canvas[row][col] = '.'; // any value that is within the square of the radius, save a dot (.)
    //                }
    //            }
    //        }
    //
    //        // print contents of the array to draw the circle
    //        for (int row = 0; row < SIZE; row++)
    //        {
    //
    //            for (int col = 0; col < SIZE; col++)
    //            {
    //                cout << canvas[row][col] << " ";
    //            }
    //
    //            cout << endl;
    //        }
    //        cout << endl;
    //    }
    //};

    // Functions declarations
    // string repl(char charToDisplay, int dispQty);
    // int showMenu(vector<string> menu);
};
void showSquare();
void showRectangle();
void showTriangle();
void showCircle();
void showMainMenu();

// main function
int main()
{
    showMainMenu();
    return 0;
}

void showSquare()
{

    Square s;
    int input = 0;
   // vector<string> menu = {
        cout << "\n****************\n";
        cout << "Square Calculator\n";
        cout << "****************** \n";
        cout << "1. Area (Area = base * base sq. units)\n";
        cout << "2. Perimeter (Perimeter = 4 * base units)\n";
        cout << "3. Go back to main menu (Shapes Calculator)\n";
        cout << "============================================\n";
        cin >> input;

    while (input != 3) {
        if (input != 3) {
            s.getData();
            s.drawShape();
        }

        switch (input) {
        case 1: {
            s.calculateArea();
            cout << "Area of square. ";
            s.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2: {
            s.calculatePerimeter();
            cout << "Perimeter of square. ";
            s.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}

void showRectangle()
{
    Shapes r;

    int choice = 0;
    //vector<string> menu = {
       cout << "\n============================================\n";
       cout << "            Rectangle Calculator\n";
       cout << "============================================\n";
       cout << "1. Area (Area = base * height sq. units)\n";
       cout << "2. Perimeter (Perimeter = 2 * (base + height) units)\n";
       cout << "3. Go back to main menu (Shapes Calculator)\n";
       cout << "============================================\n";
       cin >> choice;

    while (choice != 3) {
       // choice = showMenu(menu);
        if (choice != 3) {
            r.getData();
            r.drawShape();
        }

        switch (choice) {
        case 1: {
            r.calculateArea();
            cout << "Area of rectangle. ";
            r.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2: {
            r.calculatePerimeter();
            cout << "Perimeter of rectangle. ";
            r.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}

void showTriangle() {
    Triangle t;

    int choice = 0;
    //vector<string> menu = {
    cout << "\n============================================\n";
       cout << "            Triangle Calculator\n";
       cout << "============================================\n";
       cout << "1. Area (Area = 1/2 * base * height sq. units)\n";
       cout << "2. Perimeter (Perimeter = 2 * (base + height) units)\n";
       cout << "3. Go back to main menu (Shapes Calculator)\n";
       cout << "============================================\n ";

    while (choice != 3) {
       // choice = showMenu(menu);
        if (choice != 3) {
            t.getData();
            t.drawShape();
        }

        switch (choice) {
        case 1: {
            t.calculateArea();
            cout << "Area of triangle. ";
            t.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2: {
            t.calculatePerimeter();
            cout << "Perimeter of triangle. ";
            t.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}

void showMainMenu() {

    int choice = 0;
   // vector<string> menu = {
        cout << "*******************\n";
        cout << " Shapes Calculator\n";
        cout << "*******************\n";
        cout << "1. Square\n";
        cout << "2. Rectangle\n";
        cout << "3. Triangle\n";
        cout << "4. Circle\n";
        cout << "5. Exit\n";
        cout << "*******************\n";
        cin >> choice;
    while (choice != 5) {
        //choice = showMenu(menu);

        switch (choice) {
        case 1:
            showSquare();
            break;
        case 2:
            showRectangle();
            break;
        case 3:
            showTriangle();
            break;
        case 4:
            showCircle();
            break;

        default:
            break;
        }
    }
}
void showCircle() {

    Circle c;

    int choice = 0;
    //vector<string> menu = {
    cout << "\n============================================\n";
       cout << "            Circle Calculator\n";
       cout << "============================================\n";
       cout << "1. Area (A = pi * radius * radius sq. units)\n";
       cout << "2. Circumference (C = 2 * pi * radius units)\n";
       cout << "3. Go back to main menu (Shapes Calculator)\n";
       cout << "============================================\n";
       

    while (choice != 3) {
       // choice = showMenu(menu);
        if (choice != 3) {
            c.getData();
            c.drawShape();
        }

        switch (choice) {
        case 1: {
            c.calculateArea();
            cout << "Area of circle. ";
            c.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2: {
            c.calculatePerimeter();
            cout << "Circumference of circle. ";
            c.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}


