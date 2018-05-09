% filename: hw3_2.pl
element_pos(X, List, Pos) :-
    element_pos(X, List, 1, Pos).
element_pos(X, [X|_], Pos, Pos).
element_pos(X, [_|T], Acc, Pos) :-
    (nonvar(Pos) -> Acc < Pos ; true),  % fail if Acc hits ground Pos
    Acc1 is Acc + 1,
    element_pos(X, T, Acc1, Pos).
