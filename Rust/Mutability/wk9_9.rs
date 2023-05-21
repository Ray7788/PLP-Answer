fn main() {
    // mutable
    let mut s = String::from("hello");

    s.push_str(" world!");

    // 正常输出
    println!("{}",s);
}
