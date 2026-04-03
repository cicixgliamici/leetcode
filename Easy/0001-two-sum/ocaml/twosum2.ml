let two_sum nums target =
  (* seen: value -> index *)
  let seen = Hashtbl.create 16 in
  let n = Array.length nums in

  let rec loop i =
    if i >= n then
      [||]  (* not found -> empty array *)
    else
      let x = nums.(i) in
      let complement = target - x in
      match Hashtbl.find_opt seen complement with
      | Some j ->
          (* Found complement at index j *)
          [| j; i |]
      | None ->
          (* Store current value and continue *)
          Hashtbl.replace seen x i;
          loop (i + 1)
  in

  loop 0
