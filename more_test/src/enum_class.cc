#include <iostream>

enum class Material: uint8_t {
    DIFFUSE = 0,
    GLOSSY = 1,
    SPECULAR = 2,
    REFRACTIVE = 3
};

struct AABB {
    float tl;
    float br;

    AABB(float tl, float br): tl(tl), br(br) {}
};

struct Object {
    Material mat;
    int tag;
    AABB aabb;

    Object(): mat(Material::DIFFUSE), tag(0), aabb(0, 0) {}
    Object(int tag, float tl, float br): mat{Material::DIFFUSE}, tag(tag), aabb(tl, br) {}
};

Object *objects;

extern "C" {
    void malloc_and_copy(const Object * const objs, int num) {
        objects = new Object[num];
        for (int i = 0; i < num; i++) {
            objects[i] = objs[i];
        }
        printf("Memory allocation completed.\n");
    }

    void call_print(int num) {
        for (int i = 0; i < num; i++) {
            printf("Object type: %d, tag: %d, aabb: %f, %f\n", objects[i].mat, objects[i].tag, objects[i].aabb.tl, objects[i].aabb.br);
        }
    }

    void dealloc() {
        delete [] objects;
    }
}