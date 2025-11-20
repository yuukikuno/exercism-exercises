/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let cleaned: Vec<char> = code.chars().filter(|&char| !char.is_whitespace()).collect();
    if cleaned.len() <= 1 || cleaned.iter().any(|&char| !char.is_ascii_digit()) {
        return false;
    }
    let sum: u32 = cleaned
        .into_iter()
        .rev()
        .enumerate()
        .map(|(index, char)| {
            let digit = char.to_digit(10).unwrap();
            match (index.is_multiple_of(2), digit * 2){
                (true, _) => digit,
                (false, double) if double > 9 => double - 9,
                (false, double) => double
            }
        })
        .sum();

    sum.is_multiple_of(10)
}
