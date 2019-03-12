let component = ReasonReact.statelessComponent("Header");

let str = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <div className="header">
      <h1>(str("ReasonReact SSR Starter"))</h1>
    </div>
};
