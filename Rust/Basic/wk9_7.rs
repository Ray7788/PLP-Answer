fn main() {
    let i = 10;
    let j = i;

    // For basic types like the integer type u32, we don’t need to worry about borrowing.
    println!("{}",i);
    println!("{}",j);
}
