[@react.component]
let make = () => {
  <div>
    <p> {ReasonReact.string("This is the HOME page.")} </p>
    <Counter />
  </div>;
};