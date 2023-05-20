fn main() {
    let mut i = 10;
    let j = i;

    //need to declare i with 'let mut i = 11'
    i = 11;

    //note the value of i is not changed, even though the function argment is mutable
    increment(i);

    println!("{}",i);// 11
    println!("{}",j);// 10 unchanged
}

fn increment(mut x: u32) {
    x = x + 1;
}
