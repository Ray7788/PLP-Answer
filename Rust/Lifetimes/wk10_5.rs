fn nice <'a,'b>(x: &'a Vec<i32>, y: &'b Vec<i32>)
-> (&'b Vec<i32>,&'a Vec<i32>) {
    return (y,x);
}

// no scope used
fn main () {

    let a = vec![1,2];
    let x : &Vec<i32>;
    let b = vec![1,2,3];
    let y : &Vec<i32>;

    (x,y) = nice(&a,&b);

    println!("{}",x.len());
    println!("{}",y.len());
}
