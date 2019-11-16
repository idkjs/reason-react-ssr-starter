[@react.component]
let make =
    // ~className,
    (~href, ~children) => {
  let onClick = ev => {
    ev->ReactEvent.Synthetic.preventDefault;
    let _ = ReasonReactRouter.push(href);
    ();
  };

  <a onClick href> children </a>;
};