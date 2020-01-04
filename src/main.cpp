#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
    float mag;
} Vec3;

/*
Magnitude represents the length of a vector.
*/
void magnitude(Vec3 *v) {
    v->mag = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}

void normalise(Vec3 *v) {
    magnitude(v);
    if (v->mag > 0) {
        v->x = v->x / v->mag;
        v->y = v->y / v->mag;
        v->z = v->z / v->mag;
    }
}

// The square root of a dot product(of the same vector) is the same as the magnitude of a vector.
float dot_prod(Vec3 *v1, Vec3 *v2) {
    return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}


int main() {
    Vec3 v1 = {};
    
    v1.x = 1;
    v1.y = 3;
    v1.z = 1;
    v1.mag = sqrt(dot_prod(&v1, &v1));
    
    Vec3 v2 = {};
    
    v2.x = 2;
    v2.y = 2;
    v2.z = 20;
    v2.mag = sqrt(dot_prod(&v2, &v2));
    
    printf("V1 = X: %f | Y: %f | Z: %f | L: %f\r\n", v1.x, v1.y, v1.z, v1.mag);
    printf("V2 = X: %f | Y: %f | Z: %f | L: %f\r\n", v2.x, v2.y, v2.z, v2.mag);
    
    printf("V1 . V2: %f\r\n", dot_prod(&v1, &v2));
    
    normalise(&v1);
    normalise(&v2);
    printf("V1 . V2: %f\r\n", dot_prod(&v1, &v2));
    return 0;
}