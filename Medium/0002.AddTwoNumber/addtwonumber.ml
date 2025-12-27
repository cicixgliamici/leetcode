type listnode = { v : int; next : listnode option }

let add_two_numbers (l1 : listnode option) (l2 : listnode option) : listnode option =
  (* Recursive helper: consumes nodes and carry, returns the result list. *)
  let rec loop a b carry =
    match (a, b, carry) with
    | (None, None, 0) ->
        None  (* nothing left *)
    | _ ->
        let av, anext =
          match a with
          | None -> (0, None)
          | Some n -> (n.v, n.next)
        in
        let bv, bnext =
          match b with
          | None -> (0, None)
          | Some n -> (n.v, n.next)
        in
        let sum = av + bv + carry in
        let digit = sum mod 10 in
        let carry' = sum / 10 in
        Some { v = digit; next = loop anext bnext carry' }
  in
  loop l1 l2 0
