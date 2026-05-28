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
