let str = ReasonReact.string;
[@react.component]
let make = () => {
  <div className="header"> <h1> {str("ReasonReact SSR Starter")} </h1> </div>;
};