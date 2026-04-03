let two_sum nums target =
  let n = Array.length nums in

  (* Search for a pair starting from indices (i, j). *)
  let rec outer i =
    if i >= n then
      [||] (* not found -> empty array *)
    else
      match inner i (i + 1) with
      | Some (a, b) -> [| a; b |]
      | None -> outer (i + 1)

  and inner i j =
    if j >= n then
      None
    else if nums.(i) + nums.(j) = target then
      Some (i, j)
    else
      inner i (j + 1)
  in

  outer 0
