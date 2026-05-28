#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int CANVAS_WIDTH = 480;
const int CANVAS_HEIGHT = 360;
const int CENTER_X = CANVAS_WIDTH / 2;
const int CENTER_Y = CANVAS_HEIGHT / 2;
const int LINE_COUNT = 15;
const int STEP = 10;
const int EDGE = 150;

struct Point {
    int x;
    int y;
};

struct Color {
    int r;
    int g;
    int b;
};

int svgX(int snapX) {
    return CENTER_X + snapX;
}

int svgY(int snapY) {
    return CENTER_Y - snapY;
}

string rgb(Color color) {
    return "rgb(" + to_string(color.r) + "," + to_string(color.g) + "," + to_string(color.b) + ")";
}

void drawLine(ofstream& svg, Point start, Point end, Color color) {
    svg << "  <line x1=\"" << svgX(start.x)
        << "\" y1=\"" << svgY(start.y)
        << "\" x2=\"" << svgX(end.x)
        << "\" y2=\"" << svgY(end.y)
        << "\" stroke=\"" << rgb(color)
        << "\" stroke-width=\"1\" stroke-linecap=\"round\" />\n";
}

void drawFirstQuadrant(ofstream& svg) {
    Color green = {15, 255, 69};

    for (int i = 1; i <= LINE_COUNT; i++) {
        Point start = {0, EDGE - STEP * i};
        Point end = {STEP * i, 0};
        drawLine(svg, start, end, green);
    }
}

void drawSecondQuadrant(ofstream& svg) {
    Color yellow = {255, 234, 10};

    for (int i = 1; i <= LINE_COUNT; i++) {
        Point start = {-STEP * i, 0};
        Point end = {0, EDGE - STEP * i};
        drawLine(svg, start, end, yellow);
    }
}

void drawThirdQuadrant(ofstream& svg) {
    Color orange = {255, 187, 107};

    for (int i = 1; i <= LINE_COUNT; i++) {
        Point start = {0, -EDGE + STEP * i};
        Point end = {-STEP * i, 0};
        drawLine(svg, start, end, orange);
    }
}

void drawFourthQuadrant(ofstream& svg) {
    Color red = {255, 69, 51};

    for (int i = 1; i <= LINE_COUNT; i++) {
        Point start = {STEP * i, 0};
        Point end = {0, -EDGE + STEP * i};
        drawLine(svg, start, end, red);
    }
}

int main() {
    ofstream svg("curve_stitching.svg");

    if (!svg) {
        cerr << "Could not create curve_stitching.svg\n";
        return 1;
    }

    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << CANVAS_WIDTH
        << "\" height=\"" << CANVAS_HEIGHT
        << "\" viewBox=\"0 0 " << CANVAS_WIDTH << " " << CANVAS_HEIGHT << "\">\n";
    svg << "  <rect width=\"100%\" height=\"100%\" fill=\"white\" />\n";

    drawFirstQuadrant(svg);
    drawSecondQuadrant(svg);
    drawThirdQuadrant(svg);
    drawFourthQuadrant(svg);

    svg << "</svg>\n";
    svg.close();

    cout << "Created curve_stitching.svg\n";
    return 0;
}
