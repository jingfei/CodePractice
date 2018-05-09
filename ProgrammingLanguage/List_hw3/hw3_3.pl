% filename: hw3_3.pl
mymember(X,[X|_]).
mymember(X,[_|T]) :- mymember(X,T).

not(A) :- \+ call(A).

eliminate([],[]).
eliminate([H|T],[H|Out]) :-
    not(mymember(H,T)),
    eliminate(T,Out).
eliminate([H|T],Out) :-
    mymember(H,T),
    eliminate(T,Out).
