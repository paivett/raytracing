#include <iostream>

#define CHANNEL_TO_INT(c)   (int(255.99 * c))

using namespace std;

int main() {
    int nx = 200;
    int ny = 100;

    cout << "P3" << endl << nx << " " << ny << endl << "255" << endl;
    for (int j = 0; j < ny; ++j) {
        for (int i = 0; i < nx; ++i) {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;

            cout << CHANNEL_TO_INT(r) << " " << CHANNEL_TO_INT(g) << " " << CHANNEL_TO_INT(b) << endl;
        }
    }
}
