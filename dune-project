(lang dune 2.9)

(name react-jsx-ppx)

(license MIT)

(maintainers "David Sancho <dsnxmoreno@gmail.com>")

(authors "David Sancho <dsnxmoreno@gmail.com>")

(source
 (github ml-in-barcelona/react-jsx-ppx))

(generate_opam_files true)

(implicit_transitive_deps false)

(package
 (name react-jsx-ppx)
 (synopsis "React JSX ppx migrated to ppxlib")
 (depends
  ;; General system dependencies
  (dune (and (>= 2) (< 4)))
  (ocaml (and (>= 4.12.0) (< 5.0.0)))

  (ppxlib (= 0.27.0))

  (reason (= 3.8.1))

  ;; Dev dependencies, using with-test so that consumers don't install them (until package is released in opam)
  (ocamlformat (and (= 0.23.0) :with-test))
  (ocaml-lsp-server :with-test)
))
