#include <graphics.h>
#include <dos.h>

// Function to draw the man
void drawManWithUmbrella(int x, int y) {
    // Head
    circle(x, y - 30, 10);
    // Body
    line(x, y - 20, x, y + 20);
    // Arms
    line(x, y - 10, x - 15, y + 10); // Left arm
    line(x, y - 10, x + 15, y - 10); // Right arm holding umbrella handle

    // Legs
    line(x, y + 20, x - 10, y + 40); // Left leg
    line(x, y + 20, x + 10, y + 40); // Right leg

    // Umbrella Handle
    line(x + 15, y - 10, x + 15, y - 60); // Handle

    // Umbrella Top (semicircle)
    arc(x + 15, y - 60, 0, 180, 40); // Arc from 0° to 180°, radius 40
}

// Function to draw rain
void drawRain(int frame) {
    for (int i = 0; i < 640; i += 20) { // Increment raindrops horizontally
        if (i % 2 != 0) { // Odd i
            line(i, frame % 480, i, (frame % 480) + 10);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int manX = 320, manY = 400;

    // Run animation for 300 frames (adjust as needed)
    for (int frame = 0; frame < 300; frame++) {
        cleardevice();

        // Draw the rain
        drawRain(frame);

        // Draw the man with umbrella
        drawManWithUmbrella(manX, manY);

        // Walking animation: make the man sway slightly
        if (frame % 20 < 10) manX += 2; else manX -= 2;

        delay(50); // Adjust speed of the animation
    }

    closegraph();
    return 0;
}
