;;; file: fib.lsp

(defun fib1(n)
 (if (< n 2)
  n
  (+ (fib1 (- n 1)) (fib1 (- n 2)))
 )
)

(defun tailfact(n result result2)
 (if (< n 3)
  result
  (tailfact (- n 1) (+ result result2) result)
 )
)

(defun fib2(n)
 (tailfact n 1 1)
)

