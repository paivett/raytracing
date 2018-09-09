#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ray.h"

class Camera {
    public:  
        Camera();

        Ray get_ray(float u, float v);

    private:
        Vec3 origin, lower_left_corner, horizontal, vertical;
};

#endif // _CAMERA_H_