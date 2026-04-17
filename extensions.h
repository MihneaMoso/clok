const char* extensions[] = {
    /* ---- C / C++ ---- */
    ".c", ".h", ".cpp", ".cc", ".cxx", ".c++", ".hpp", ".hh", ".hxx", ".h++", ".inl", ".ipp", ".tcc", ".tpp",

    /* ---- Assembly ---- */
    ".asm", ".s", ".S", ".nasm", ".inc",

    /* ---- C# / .NET ---- */
    ".cs", ".csx", ".vb", ".vbs", ".vba", ".fs", ".fsx", ".fsi", ".fsscript",

    /* ---- Java / JVM ---- */
    ".java", ".jav", ".groovy",

    /* ---- Clojure ---- */
    ".clj", ".cljs", ".cljc", ".cljr", ".edn",

    /* ---- Python ---- */
    ".py", ".pyw", ".pyx", ".pxd", ".pxi", ".rpy", ".pyi", ".pyc",

    /* ---- Ruby ---- */
    ".rb", ".rbw", ".rake", ".gemspec", ".ru", ".erb",

    /* ---- Perl ---- */
    ".pl", ".pm", ".pod", ".t", ".psgi",

    /* ---- PHP ---- */
    ".php", ".php3", ".php4", ".php5", ".php7", ".php8", ".phtml", ".phar",

    /* ---- JavaScript / TypeScript ---- */
    ".js", ".mjs", ".cjs", ".jsx", ".ts", ".tsx", ".mts", ".cts", ".d.ts",

    /* ---- CoffeeScript / LiveScript ---- */
    ".coffee", ".litcoffee", ".ls",

    /* ---- Web / Markup ---- */ ".html", ".htm", ".xhtml", ".shtml", ".xml", ".xsl", ".xslt", ".xsd", ".dtd", ".rss", ".atom", ".wsdl", ".xquery", ".xq", ".xql", ".xqm", ".svg", ".mathml", ".plist",

    /* ---- CSS / Preprocessors ---- */
    ".css", ".scss", ".sass", ".less", ".styl", ".stylus", ".pcss", ".postcss",

    /* ---- Templating / View engines ---- */
    ".vue", ".svelte", ".astro", ".haml", ".slim", ".pug", ".jade", ".ejs", ".hbs", ".mustache", ".handlebars", ".twig", ".liquid", ".njk", ".jinja", ".jinja2", ".j2", ".eco", ".ect", ".swig", ".erb", ".tmpl", ".template", ".tt", ".tt2",

    /* ---- Shell / Scripting ---- */
    ".sh", ".bash", ".zsh", ".fish", ".ksh", ".csh", ".tcsh", ".bat", ".cmd", ".ps1", ".psm1", ".psd1", ".psc1",

    /* ---- Go ---- */
    ".go", ".mod", ".sum",

    /* ---- Rust ---- */
    ".rs", ".rlib",

    /* ---- Swift ---- */
    ".swift",

    /* ---- Kotlin ---- */
    ".kt", ".kts",

    /* ---- Groovy ---- */
    ".gvy", ".gy", ".gsh",

    /* ---- Scala ---- */
    ".scala", ".sc", ".sbt",

    /* ---- Dart ---- */
    ".dart",

    /* ---- Objective-C ---- */
    ".m", ".mm",

    /* ---- Lua ---- */
    ".lua", ".luac",

    /* ---- R ---- */
    ".r", ".R", ".Rmd", ".Rnw", ".Rprofile", ".Renviron",

    /* ---- Julia ---- */
    ".jl",

    /* ---- MATLAB / Octave ---- */
    ".mat", ".mlx", ".oct",

    /* ---- Mathematica / Wolfram ---- */
    ".nb", ".wl", ".wls", ".m",

    /* ---- Haskell ---- */
    ".hs", ".lhs", ".hsc", ".hs-boot",

    /* ---- Elm ---- */
    ".elm",

    /* ---- Elixir / Erlang ---- */
    ".ex", ".exs", ".eex", ".heex", ".leex", ".erl", ".hrl", ".app", ".escript",

    /* ---- OCaml / F# / ML ---- */
    ".ml", ".mli", ".mll", ".mly", ".sml", ".sig", ".fun",

    /* ---- Racket / Scheme / Lisp ---- */
    ".rkt", ".rktl", ".scm", ".ss", ".sls", ".sps", ".lisp", ".lsp", ".cl", ".el", ".fnl",


    /* ---- Hy (Lisp on Python) ---- */
    ".hy",

    /* ---- PureScript ---- */
    ".purs",

    /* ---- ReasonML / ReScript ---- */
    ".re", ".rei", ".res", ".resi",

    /* ---- Idris ---- */
    ".idr", ".lidr",

    /* ---- Agda ---- */
    ".agda", ".lagda",

    /* ---- Coq ---- */
    ".v", ".coq",

    /* ---- Lean ---- */
    ".lean", ".olean",

    /* ---- Prolog ---- */
    ".pro", ".prolog", ".P",

    /* ---- Ada ---- */
    ".ada", ".adb", ".ads", ".gpr",

    /* ---- COBOL ---- */
    ".cob", ".cbl", ".cpy", ".cpy",

    /* ---- Fortran ---- */
    ".f", ".for", ".ftn", ".f77", ".f90", ".f95", ".f03", ".f08", ".F", ".F90",

    /* ---- Pascal / Delphi ---- */
    ".pas", ".pp", ".dpr", ".dfm", ".lpr", ".lpk", ".lfm",

    /* ---- D ---- */
    ".d", ".di",

    /* ---- Nim ---- */
    ".nim", ".nimble", ".nims",

    /* ---- Zig ---- */
    ".zig", ".zon",

    /* ---- V (vlang) ---- */
    ".v", ".vsh",

    /* ---- Odin ---- */
    ".odin",

    /* ---- Crystal ---- */
    ".cr",

    /* ---- Hack ---- */
    ".hack", ".hh",

    /* ---- Pony ---- */
    ".pony",

    /* ---- Red / Rebol ---- */
    ".red", ".reds", ".r", ".reb",

    /* ---- Factor ---- */
    ".factor",

    /* ---- Forth ---- */
    ".forth", ".fth", ".4th", ".fs",

    /* ---- APL / Dyalog / J / K / Q ---- */
    ".apl", ".dyalog", ".aplf", ".apln", ".aplo", ".j", ".ijs", ".k", ".q", ".quke",

    /* ---- Io ---- */
    ".io",

    /* ---- Tcl / Tk ---- */
    ".tcl", ".tk", ".tbc",

    /* ---- AWK / Sed ---- */
    ".awk", ".sed",

    /* ---- ABAP ---- */
    ".abap",

    /* ---- ColdFusion ---- */
    ".cfm", ".cfml", ".cfc",

    /* ---- ActionScript / Flex ---- */
    ".as", ".mxml",

    /* ---- Haxe ---- */
    ".hx", ".hxml",

    /* ---- Godot / GDScript ---- */
    ".gd", ".gdshader", ".gdns", ".gdnlib", ".tscn", ".tres",

    /* ---- Pico-8 ---- */
    ".p8",

    /* ---- AutoHotkey / AutoIt ---- */
    ".ahk", ".ahkl", ".au3",

    /* ---- NSIS installer scripts ---- */
    ".nsi", ".nsh",

    /* ---- Inno Setup ---- */
    ".iss",

    /* ---- Solidity / EVM ---- */
    ".sol", ".yul",

    /* ---- Vyper ---- */
    ".vy",

    /* ---- Cairo (StarkNet) ---- */
    ".cairo",

    /* ---- Move (Aptos/Sui) ---- */
    ".move",

    /* ---- FunC / Tact (TON) ---- */
    ".fc", ".func", ".tact",

    /* ---- Shader languages ---- */
    ".glsl", ".vert", ".frag", ".geom", ".tesc", ".tese", ".comp", ".hlsl", ".fx", ".fxh", ".wgsl", ".metal", ".spvasm", ".cg",

    /* ---- SQL / Query languages ---- */
    ".sql", ".mysql", ".pgsql", ".plsql", ".tsql", ".hql", ".bql", ".graphql", ".gql", ".sparql", ".rq", ".cypher", ".cql", ".flux", ".fql",

    /* ---- Config / Infrastructure ---- */
    ".tf", ".tfvars", ".hcl", ".nomad", ".pkr.hcl", ".bicep", ".arm", ".nix", ".dhall", ".cue", ".jsonnet", ".libsonnet", ".pkl", ".star", ".starlark", ".bzl", ".bazel", ".BUILD", ".cmake", ".make", ".mk", ".mak", ".ninja", ".gyp", ".gypi", ".dockerfile", ".containerfile", ".vagrantfile", ".gemfile", ".rakefile", ".capfile", ".podfile", ".procfile", ".brewfile",

    /* ---- JSON ---- */
    ".json", ".json5", ".jsonc", ".jsonl", ".ndjson",

    /* ---- YAML ---- */
    ".yaml", ".yml", ".toml", ".ini", ".cfg", ".conf", ".config",

    /* ---- ENV ---- */
    ".env", ".properties", ".props",

    /* ---- CSV ---- */
    ".csv", ".tsv", ".ssv", ".psv", ".dsv",

    /* ---- Log ---- */
    ".log", ".txt",

    /* ---- Dotfiles / Editor config ---- */
    ".editorconfig", ".gitignore", ".gitattributes", ".gitmodules", ".npmrc", ".nvmrc", ".yarnrc", ".babelrc", ".eslintrc", ".prettierrc", ".stylelintrc", ".huskyrc", ".lintstagedrc", ".browserslistrc", ".mocharc", ".jestrc", ".nycrc", ".czrc", ".commitlintrc", ".releaserc",

    /* ---- Markdown / Documentation ---- */
    ".md", ".markdown", ".mdown", ".mkd", ".mdx",
    ".rst", ".rest",
    ".adoc", ".asciidoc", ".asc",
    ".tex", ".latex", ".ltx", ".sty", ".cls", ".bib", ".bst",
    ".org", ".textile", ".rdoc", ".pod", ".wiki", ".mediawiki",
    ".creole", ".dita", ".docbook",

    /* ---- Localization / i18n ---- */
    ".po", ".pot", ".strings", ".stringsdict", ".resx", ".resw", ".xlf", ".xliff", ".arb",

    /* ---- IDL / Interface ---- */
    ".idl", ".midl", ".webidl", ".widl", ".proto", ".thrift", ".avsc", ".avdl", ".fbs", ".capnp", ".flatbuffers", ".smithy", ".raml",

    /* ---- Embedded / Device ---- */
    ".dts", ".dtsi", ".ld", ".lds", ".ldi",

    /* ---- Diff / Patch ---- */
    ".diff", ".patch",

    /* ---- Cert / Crypto (PEM, text-encoded) ---- */
    ".pem", ".crt", ".cer", ".key", ".pub", ".asc",

    /* ---- Windows Registry (text export) ---- */
    ".reg",

    /* ---- Setup / INF ---- */
    ".inf",

    /* ---- Desktop entry (Linux) ---- */
    ".desktop",

    /* ---- Cron / Systemd ---- */
    ".service", ".timer", ".socket", ".mount", ".unit",


    /* ---- Notebook formats (text-based) ---- */
    ".ipynb",

    /* ---- BDD / Testing ---- */
    ".feature", ".story", ".robot", ".spec", ".test",

    /* ---- Modula / Oberon ---- */
    ".mod", ".def", ".ob2", ".ooc",

    /* ---- Eiffel ---- */
    ".e", ".ecf",

    /* ---- Smalltalk ---- */
    ".st", ".gst",

    /* ---- VHDL / Verilog (HDL) ---- */
    ".vhd", ".vhdl", ".v", ".sv", ".svh", ".vh",


    /* ---- Batch / Make extras ---- */
    ".msbuild", ".proj", ".props", ".targets", ".nuspec", ".csproj", ".vbproj", ".fsproj", ".vcxproj", ".sln", ".ruleset",

    /* ---- OpenAPI / Swagger ---- */
    ".oas", ".swagger",

    /* ---- ASP / Server pages ---- */
    ".asp", ".aspx", ".ascx", ".ashx", ".asmx", ".cshtml", ".vbhtml", ".razor",

    /* ---- JSP / Server-side Java ---- */
    ".jsp", ".jspx", ".jstl", ".tag", ".tagx",

    /* ---- PL/I ---- */
    ".pli", ".pl1", ".pl/i",

    /* ---- RPG (IBM i) ---- */
    ".rpg", ".rpgle", ".sqlrpgle", ".clle",

    /* ---- MUMPS / Cache ObjectScript ---- */
    ".m", ".csp", ".cls",

    /* ---- OpenEdge ABL / Progress ---- */
    ".p", ".cls", ".w", ".i",

    /* ---- Logtalk ---- */
    ".lgt", ".logtalk",

    /* ---- Oz ---- */
    ".oz",

    /* ---- Grace ---- */
    ".grace",


    /* ---- Janet ---- */
    ".janet", ".jdn",

    /* ---- Gleam ---- */
    ".gleam",

    /* ---- Grain ---- */
    ".gr",

    /* ---- Roc ---- */
    ".roc",

    /* ---- Ante ---- */
    ".an",

    /* ---- Koka ---- */
    ".kk", ".kki",

    /* ---- Unison ---- */
    ".u",

    /* ---- Bosque ---- */
    ".bsq",

    /* ---- Inko ---- */
    ".inko",

    /* ---- Wren ---- */
    ".wren",

    /* ---- Squirrel ---- */
    ".nut",

    /* ---- Ring ---- */
    ".ring",

    /* ---- MoonScript ---- */
    ".moon",

    /* ---- Terra ---- */
    ".t",

    /* ---- Chaiscript ---- */
    ".chai",

    /* ---- Felix ---- */
    ".flx", ".flxh",

    /* ---- Genie ---- */
    ".gs",

    /* ---- Vala ---- */
    ".vala", ".vapi",

    /* ---- Boo ---- */
    ".boo",

    /* ---- Nemerle ---- */
    ".n",

    /* ---- Oxygene ---- */
    ".oxygene",

    /* ---- Mercury ---- */
    ".m", ".moo",

    /* ---- Curry ---- */
    ".curry",

    /* ---- Clean ---- */
    ".icl", ".dcl",

    /* ---- Frege ---- */
    ".fr",

    /* ---- Gosu ---- */
    ".gs", ".gsx", ".gsp", ".gst",


    /* ---- Turtle / N-Triples / RDF ---- */
    ".ttl", ".n3", ".nt", ".nq", ".trig", ".jsonld",

    /* ---- HCL extras ---- */
    ".sentinel",

    /* ---- Cadence (Flow blockchain) ---- */
    ".cdc",

    /* ---- Clarity (Stacks/Bitcoin) ---- */
    ".clar",

    /* ---- Michelson (Tezos) ---- */
    ".tz", ".tez",

    /* ---- WebAssembly text format ---- */
    ".wat", ".wast",

    /* ---- Alloy ---- */
    ".als",

    /* ---- TLA+ ---- */
    ".tla", ".cfg",

    /* ---- Isabelle ---- */
    ".thy",

    /* ---- Z notation ---- */
    ".zed",

    /* ---- PROMELA (Spin) ---- */
    ".pml", ".promela",

    /* ---- Lustre / Scade ---- */
    ".lus",

    /* ---- VXML / SSML (voice/speech XML) ---- */
    ".vxml", ".ssml", ".grxml",

    /* ---- YANG (network config modeling) ---- */
    ".yang",


    /* ---- Stan (statistical modeling) ---- */
    ".stan",

    /* ---- BUGS / JAGS ---- */
    ".bug", ".jag",

    /* ---- SWIG ---- */
    ".i", ".swg",

    /* ---- Lex / Yacc / Bison / ANTLR ---- */
    ".l", ".lex", ".y", ".yy", ".ypp", ".g", ".g4", ".jj", ".jjt",

    /* ---- Emacs / Vim config ---- */
    ".vim", ".vimrc", ".el", ".emacs",

    /* ---- Nushell ---- */
    ".nu",

    /* ---- Elvish ---- */
    ".elv",

    /* ---- Xonsh ---- */
    ".xsh",

    /* ---- PowerQuery (M) ---- */
    ".pq", ".pqm",

    /* ---- DAX ---- */
    ".dax",

    /* ---- Pig Latin ---- */
    ".pig",

    /* ---- AMPL ---- */
    ".mod", ".dat", ".run",

    /* ---- Modelica ---- */
    ".mo",

    /* ---- Simulink (text export) ---- */
    ".mdl", ".slx",

    /* ---- POV-Ray ---- */
    ".pov", ".inc",

    /* ---- OpenSCAD ---- */
    ".scad",

    /* ---- GCode ---- */
    ".gcode", ".gco", ".nc", ".ngc",

    NULL  /* sentinel */
};
