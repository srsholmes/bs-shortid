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
/* Generate an ID */
let myId = ShortId.generate(); 
/* Check if ID is valid */
let myVal = ShortId.isValid(yId); 
/* Get characters of short Id */
let myDict = ShortId.characters();
/* Set characters of short Id */
let myDict = ShortId.characters(~chars="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$@", ())
```

## Development

```sh
npm run start
``` 
