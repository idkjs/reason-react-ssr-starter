[@react.component]
let make = () => {
  <div>
    <p> {ReasonReact.string("This is the About page.")} </p>
    <Counter />
  </div>;
};

let default = make;
