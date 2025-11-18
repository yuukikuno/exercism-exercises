use std::str::Chars;

/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let cleaned: Vec<char> = code.chars().filter(|&char| char != ' ').collect();
    if cleaned.len() <= 1 || cleaned.iter().any(|&char| !char.is_ascii_digit()) {
        return false;
    }
    let result: u32 = cleaned
        .into_iter()
        .rev()
        .enumerate()
        .map(|(index, char)| {
            let digit = char.to_digit(10).unwrap();
            if index.is_multiple_of(2) {
                return digit;
            }
            let double = digit * 2;
            if double > 9 { double - 9 } else { double }
        })
        .sum();

    result.is_multiple_of(10)
}
