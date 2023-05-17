fn main() {
    let mut s = String::from("hello");

    s.push_str(" world!");

    let t = &mut s;

    t.push_str(" And universe!");

    // 调换顺序
    println!("{}",t);
    //works fine, Rust sees that t is never used again after line above
    //so mutable and immutable borrow don't occur "at the same time"
    println!("{}",s);
}
