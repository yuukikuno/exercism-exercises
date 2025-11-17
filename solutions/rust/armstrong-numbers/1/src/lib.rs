pub fn is_armstrong_number(num: u32) -> bool {
    let digits: Vec<u32> = num
        .to_string()
        .chars()
        .filter(|x| x.is_numeric())
        .map(|d| d.to_digit(10).unwrap())
        .collect();
    num == digits
        .iter()
        .copied()
        .map(|x| x.pow(digits.len() as u32))
        .reduce(|acc, e| acc + e)
        .unwrap()
}
