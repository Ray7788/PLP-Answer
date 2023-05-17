// missing lifetime specifier
fn nice (x: &Vec<i32>, y: &Vec<i32>)
  -> ( &Vec<i32>, &Vec<i32>) {
    return (y,x);
}

fn main() {
    let a = vec![6,5,];
    println!("{}",a.len());

    let x: &Vec<i32>;
    {
     let b = vec![7,8,9];
     let y: &Vec<i32>;
     (x,y) = nice(&a,&b);
     println!("{}",y.len());
    }

    print!("{}",x.len());
}
// can not run!!!