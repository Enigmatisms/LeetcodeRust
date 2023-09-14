use std::collections::HashMap;
use std::hash::Hash;
use std::fmt::Display;

fn process(s: &mut String) {

}

struct List<T> where T: Display {
  head: Option<Box<ListNode<T>>>
}


struct ListNode<T> where T: Display {
  value: T,
  next: Option<Box<ListNode<T>>>,
}

impl<T> List<T> where T: Display {
  pub fn new() -> Self {
    List {
      head: None
    }
  }

  pub fn push(&mut self, val: T) {
    let new_node: ListNode<T> = ListNode { value: val, next: self.head.take()};
    self.head = Some(Box::new(new_node));
  }

  pub fn display(&self) {
    let mut ptr = self.head.as_ref();
    while let Some(inner) = ptr {
      print!("{} -> ", inner.value);
      ptr = inner.next.as_ref();
    }
    println!("");
  }
}

fn to_refs<T>(mut list: &mut List<T>) -> Vec<&mut T> where T: Display {
  let mut node = list.head.as_mut().unwrap();   // if head is None, this will be false
  let mut result = vec![];
  loop {
      result.push(&mut node.value);
      if let Some(n) = node.next.as_mut() {
          node = n;
      } else {
          return result;
      }
  }
}                                      // v

use std::time::Instant;

fn main() {
  let start = Instant::now();
  let a = String::from("-".repeat(10000));
  for i in 0..10000 {
    // let mut a = format!("{:->1$}", "Q", i);
    let mut b = a.clone();
    b.replace_range(i..i + 1, "Q");
  }
  let time_sum = start.elapsed().as_secs_f32();
  println!("Time sum: {} s, average time: {} s", time_sum, time_sum / 10000.);
}
