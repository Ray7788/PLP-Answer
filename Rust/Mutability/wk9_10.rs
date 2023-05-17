fn main() {
    let mut s = String::from("hello");

    s.push_str(" world!");

    let mut t = s;

    t.push_str(" And universe!");

    // t takes the ownership of s, can not be used, move to line before let mut t = s;
    //println!("{}",s);
    println!("{}",t);
}
