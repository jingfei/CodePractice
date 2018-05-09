add(X,[],[X]).
add(X,[A|L],[A|L1]):-
 add(X,L,L1).
