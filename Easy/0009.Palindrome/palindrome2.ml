let is_palindrome x =
  (* Negative numbers are not palindromes.
     If it ends with 0, it can only be palindrome if it's exactly 0. *)
  if x < 0 || (x mod 10 = 0 && x <> 0) then false
  else
    let rec loop n rev_half =
      (* Stop when we've processed at least half the digits. *)
      if n <= rev_half then
        (n = rev_half) || (n = rev_half / 10)
      else
        let last_digit = n mod 10 in
        loop (n / 10) (rev_half * 10 + last_digit)
    in
    loop x 0
