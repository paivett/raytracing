#include "camera.h"

Camera::Camera() : origin(0.0, 0.0, 0.0),
                   lower_left_corner(-2.0, -1.0, -1.0),
                   horizontal(4.0, 0.0, 0.0), 
                   vertical (0.0, 2.0, 0.0) {

}

Ray Camera::get_ray(float u, float v) {
    return Ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}