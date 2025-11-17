pub fn is_armstrong_number(num: u32) -> bool {
    let num_string = num.to_string();
    let length = num_string.len() as u32;
    num == num_string
        .chars()
        .filter_map(|x| x.to_digit(10))
        .map(|d| d.pow(length))
        .sum()
}
