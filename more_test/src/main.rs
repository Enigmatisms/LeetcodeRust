extern crate libc;

#[repr(C)]
pub struct AABB {
    pub tl: libc::c_float,
    pub br: libc::c_float
}

#[repr(C)]
pub struct Object {
    pub mat: libc::c_uchar,
    pub tag: libc::c_int,
    pub aabb: AABB
}

impl AABB {
    pub fn new(tl: libc::c_float, br: libc::c_float) -> AABB {
        AABB{tl: tl, br: br}
    }
}

impl Object {
    pub fn new(mat: libc::c_uchar, tag: libc::c_int, tl: libc::c_float, br: libc::c_float) -> Object {
        Object {
            mat: mat, tag: tag,
            aabb: AABB{tl: tl, br: br}
        }
    }
}

#[link(name = "enum_class", kind = "static")]
extern {
    pub fn malloc_and_copy(ptr: *const Object, num: libc::c_int);

    pub fn call_print(num: libc::c_int);

    pub fn dealloc();
}

fn main() {
    let mut vector: Vec<Object> = Vec::new();
    vector.push(Object::new(0, 4, 1.5, 2.0));
    vector.push(Object::new(1, 3, 1.4, -2.0));
    vector.push(Object::new(1, 2, 1.3, 2.0));
    vector.push(Object::new(0, 1, 1.2, -2.0));
    vector.push(Object::new(2, 2, 1.1, 2.0));
    vector.push(Object::new(3, 3, 1.0, -2.0));
    vector.push(Object::new(2, 4, 0.9, 0.0));

    unsafe {
        malloc_and_copy(vector.as_ptr(), vector.len() as libc::c_int);
        call_print(vector.len() as libc::c_int);
        dealloc();
    }
}
