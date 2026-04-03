let is_palindrome (x : int) : bool =
  (* Negative numbers are not palindromes. *)
  if x < 0 then false
  else
    let original = Int64.of_int x in
    let int32_max = Int64.of_int32 Int32.max_int in

    let rec loop (n : int) (rev : int64) : int64 option =
      if n = 0 then Some rev
      else
        let last_digit = n mod 10 in
        let last64 = Int64.of_int last_digit in

        (* Overflow check for rev*10 + last_digit against Int32.max_int *)
        if rev > Int64.div (Int64.sub int32_max last64) 10L then None
        else
          let rev' = Int64.add (Int64.mul rev 10L) last64 in
          loop (n / 10) rev'
    in

    match loop x 0L with
    | None -> false
    | Some reversed -> Int64.equal original reversed
