type t;

[@bs.module] external shortid : t = "shortid";

[@bs.module "shortid"] external generate : unit => string = "";

[@bs.module "shortId"] external getCharacters : unit => string = "characters";
[@bs.module "shortId"] external setCharacters : string => string = "characters";

let characters = (~chars=?, ()) =>
  switch (chars) {
  | None => getCharacters()
  | Some(c) => setCharacters(c)
  };

[@bs.module "shortid"] external isValid : string => bool = "";

[@bs.module "shortid"] external worker : int => unit = "";

[@bs.module "shortid"] external seed : int => unit = "";
