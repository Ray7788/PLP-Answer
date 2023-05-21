fn main() {
    let mut s = String::from("hello");

    s.push_str(" world!");

    let t = &mut s;

    t.push_str(" And universe!");

    // causes error: try to borrow immutable s
    println!("{}",s);
    println!("{}",t);
}
// mutable borrow can't coexist with other borrow (t) 