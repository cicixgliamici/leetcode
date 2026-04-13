let two_sum nums target =
  (* 
     Hash table that stores numbers we have already seen.
     Key   = value of the number
     Value = index where that number appears
  *)
  let seen = Hashtbl.create 16 in

  (* Length of the input array. *)
  let n = Array.length nums in

  (*
     loop i:
     scans the array from left to right.
     For each element nums.(i), it computes the value
     needed to reach the target, namely:
         complement = target - nums.(i)

     Then it checks whether that complement has already
     been seen before.
  *)
  let rec loop i =
    (* If we reach the end, no valid pair was found. *)
    if i >= n then
      [||]  (* Return an empty array if no solution exists. *)
    else
      (* Current number at position i. *)
      let x = nums.(i) in

      (* Value needed so that x + complement = target. *)
      let complement = target - x in

      (* Check whether the complement was already encountered. *)
      match Hashtbl.find_opt seen complement with
      | Some j ->
          (*
             We found a previous index j such that:
             nums.(j) + nums.(i) = target

             So we return the pair of indices.
          *)
          [| j; i |]
      | None ->
          (*
             The complement has not been seen yet,
             so we store the current value x with its index i
             and continue with the next position.
          *)
          Hashtbl.replace seen x i;
          loop (i + 1)
  in

  (* Start scanning from index 0. *)
  loop 0
