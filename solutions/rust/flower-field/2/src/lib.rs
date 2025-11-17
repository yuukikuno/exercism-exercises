use std::ops::RangeInclusive;

pub fn annotate(garden: &[&str]) -> Vec<String> {
    garden
        .iter()
        .enumerate()
        .map(|(row_index, row)| {
            row.as_bytes()
                .iter()
                .enumerate()
                .map(|(column_index, byte)| match byte {
                    b'*' => '*',
                    b' ' => adjacent_flower_count(garden, row_index, column_index),
                    _ => panic!("Should not have other characters"),
                })
                .collect()
        })
        .collect()
}

fn adjacent_flower_count(garden: &[&str], row_index: usize, column_index: usize) -> char {
    let count = garden[neighbor_range(garden, row_index)]
        .iter()
        .flat_map(|neighbor_row| {
            let bytes = neighbor_row.as_bytes();
            bytes[neighbor_range(bytes, column_index)].iter()
        })
        .filter(|&&adjacent_cell| adjacent_cell == b'*')
        .count();
    match count {
        0 => ' ',
        _ => (b'0' + count as u8) as char,
    }
}

fn neighbor_range<T>(slice: &[T], index: usize) -> RangeInclusive<usize> {
    index.saturating_sub(1)..=(index + 1).min(slice.len() - 1)
}
