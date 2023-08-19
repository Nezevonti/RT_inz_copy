#include "Sphere.h"


bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const {
    Vec3 oc = r.origin - center;
    float a = dot(r.direction, r.direction);
    float b = dot(oc, r.direction);
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = mat_ptr;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = mat_ptr;
            return true;
        }
    }
    return false;
}

void Sphere::setAABB() {
    Vec3 tmp = Vec3(radius + FLT_EPSILON, radius + FLT_EPSILON, radius + FLT_EPSILON);
    this->boundingBox.minPoint = this->center - tmp;
    this->boundingBox.maxPoint = this->center + tmp;
}