clause_tree(true) :- !.  % true leaf
clause_tree((G,R)) :-
	!,
	clause_tree(G),
	clause_tree(R).		% search each branch
clause_tree(G) :-
	clause(G,Body),
	clause_tree(Body).	% grow branches

member(X,[X|_]).
member(X,[_|R]) :- member(X,R).
