extern crate libc;
use std::fs;
use serde::de::DeserializeOwned;
use std::io::BufReader;
use serde_derive::{Deserialize, Serialize};

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

#[derive(Deserialize, Serialize, Clone)]
pub struct ObjInfoJson {
    _type: u8,
    ref_index: f32,
    u_a: f32,
    u_s: f32,
    p_c: f32
}

#[derive(Deserialize, Serialize, Clone)]
pub struct ObjVecJson {
    objs: Vec<ObjInfoJson>
}

pub fn read_config<RType: DeserializeOwned, PathType: AsRef<std::path::Path>>(file_path: PathType) -> RType {
    let file: fs::File = fs::File::open(file_path).ok().unwrap();
    let reader = BufReader::new(file);
    let config: RType = serde_json::from_reader(reader).ok().unwrap();
    config
}

fn main() {
    let obj_vec = read_config::<ObjVecJson, _>("./test.json");
    for (i, obj) in obj_vec.objs.iter().enumerate() {
        println!("Object {i}: type = {}, ref_index = {}, u_a = {}, u_s = {}, p_c = {}", obj._type, obj.ref_index, obj.u_a, obj.u_s, obj.p_c);
    }
}
