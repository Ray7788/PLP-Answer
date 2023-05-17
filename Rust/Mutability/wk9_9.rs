fn main() {
    // mutable
    let mut s = String::from("hello");

    s.push_str(" world!");

    println!("{}",s);
}
