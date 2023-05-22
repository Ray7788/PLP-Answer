// Question 1
// 本段代码是正常输出的
fn main() {
    let v = vec![2,3,5,7];
    let a = &v;
    let _c = a;
    let _b = v;

    println!("{}", _b.len());
}