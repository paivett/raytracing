#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ray.h"

class Camera {
    public:  
        Camera(const Vec3& look_from, const Vec3& look_at, const Vec3& vup, float vfov, float aspect, float aperture, float focus_dist, float aperture_interval);

        Ray get_ray(float u, float v);

    private:
        Vec3 origin, lower_left_corner, horizontal, vertical;
        Vec3 u, v, w;
        float lens_radius;
        // How many seconds the aperture of the camera lasts
        float aperture_interval;
};

#endif // _CAMERA_H_