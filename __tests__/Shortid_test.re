open Jest;

open ExpectJs;

let uniq = lst => {
  let unique_set = Hashtbl.create(List.length(lst));
  List.iter(x => Hashtbl.replace(unique_set, x, ()), lst);
  Hashtbl.fold((x, (), xs) => [x, ...xs], unique_set, []);
};

describe("ShortId", () => {
  let myList = Array.init(10000, i => i) |> Array.map(x => ShortId.generate()) |> ArrayLabels.to_list;
  let uniqList = uniq(myList);
  test("There are no duplicates in 10000 IDs", () =>
    expect(List.length(myList)) |> toBe(List.length(uniqList))
  );
});

describe("Characters", () => {
  test("IsValid", () =>
    expect(ShortId.characters()) |> toBe("ylZM7VHLvOFcohp01x-fXNr8P_tqin6RkgWGm4SIDdK5s2TAJebzQEBUwuY9j3aC")
  );
  test("IsValid", () =>
    expect(ShortId.characters(~chars="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$@", ()))
    |> toBe("BmG@HyPTuqjXiz8VWIvOUDFbJ$451Sdh3te0of9lKQx2CLAR76YcsknwgNEprZaM")
  );
});

describe("IsValid", () => {
  test("IsValid", () =>
    expect(ShortId.isValid("N1aGxE")) |> toBe(true)
  );
  test("IsValid", () =>
    expect(ShortId.isValid("N1M6GeN")) |> toBe(true)
  );
  test("IsValid", () =>
    expect(ShortId.isValid("41-aGe4")) |> toBe(true)
  );
  test("IsValid", () =>
    expect(ShortId.isValid("7J--Cn7_Y")) |> toBe(true)
  );
  test("IsValid", () =>
    expect(ShortId.isValid("7kb-y6XdF")) |> toBe(true)
  );
  test("IsValid", () =>
    expect(ShortId.isValid("i have spaces")) |> toBe(false)
  );
  test("IsValid", () =>
    expect(ShortId.isValid("i have \n breaks \n of \n the \n lines")) |> toBe(false)
  );
  test("IsValid", () =>
    expect(ShortId.isValid("abc")) |> toBe(false)
  );
});
