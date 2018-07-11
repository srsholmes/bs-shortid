# bs-shortid

Bucklescript/Reason bindings for [shortId](https://github.com/dylang/shortid)

## Installation

```sh
npm install --save bs-shortid
```

In your `bsconfig.json`, include `"bs-shortid"` in the `bs-dependencies`.

## Usage

See `__tests__/ShortId_test.re` for sample usage.

```reason
let myId = ShortId.generate(); // Generates a shortId.
let myVal = ShortId.isValid("N1aGxE"); // True
let myDict = ShortId.characters(); // String of chars
```

## Development

```sh
npm run start
``` 
