#include "colors.h"

// Definitions of global color variables
Color darkGrey = {26,31,40,255};
Color green = {47, 230, 23, 255};
Color red = {232, 18, 18, 255};
Color orange = {226, 116, 17, 255};
Color yellow = {237, 234, 4, 255};
Color purple = {166, 0, 247, 255};
Color cyan = {21, 204, 209, 255};
Color blue = {13, 64, 216, 255};

// Definition of GetCellColors function
std::vector<Color> GetCellColors() {
    std::vector<Color> colors = { darkGrey, green, red, orange, yellow, purple, cyan, blue };
    return colors;
}

