let two_sum nums target =
  (* Total number of elements in the input array. *)
  let n = Array.length nums in

  (* 
     outer i:
     tries to fix the first index of the pair as i,
     then searches for a second index j > i such that
     nums.(i) + nums.(j) = target.
  *)
  let rec outer i =
    (* If i reaches the end, no valid pair was found. *)
    if i >= n then
      [||]  (* Return an empty array if no solution exists. *)
    else
      (* Search for a matching second index starting from i + 1. *)
      match inner i (i + 1) with
      | Some (a, b) ->
          (* A valid pair of indices was found. *)
          [| a; b |]
      | None ->
          (* No pair found with index i, so try the next i. *)
          outer (i + 1)

  (* 
     inner i j:
     given a fixed first index i, scans all indices j > i
     looking for a pair whose sum is equal to target.
  *)
  and inner i j =
    (* If j reaches the end, no pair was found for this i. *)
    if j >= n then
      None
    (* Check whether nums.(i) and nums.(j) form the required sum. *)
    else if nums.(i) + nums.(j) = target then
      Some (i, j)
    else
      (* Otherwise continue searching with the next j. *)
      inner i (j + 1)
  in

  (* Start searching from the first index. *)
  outer 0
